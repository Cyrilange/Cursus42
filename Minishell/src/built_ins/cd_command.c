#include "../includes/minishell.h"

static int change_pwd(void)
{
    char *cwd = getcwd(NULL, 0);
    if (!cwd)
        return 1;
    setenv("PWD", cwd, 1);

    free(cwd);
    return 0;
}

static int cd_home(void)
{
	const char *home = getenv("HOME");
	const char *pwd = getenv("PWD");
	if (pwd)
		setenv("OLDPWD", pwd, 1);
	if (!home)
	{
		write(2, "minishell: cd: HOME not set\n", 29);
		return 1;
	}
	if (chdir(home) == 0)
	{
		setenv("PWD", home, 1);
		return 0;
    }
    return 1;
}

static int cd_error(char *path)
{
    fprintf(stderr, "minishell: cd: `%s`: %s\n", path, strerror(errno));
    return 1;
}

int ft_cd(char *path)
{
    if (!path || *path == '\0')
        return cd_home();

    if (chdir(path) != 0)
        return cd_error(path);
    const char *pwd = getenv("PWD");
    if (pwd)
        setenv("OLDPWD", pwd, 1);

    return change_pwd();
}