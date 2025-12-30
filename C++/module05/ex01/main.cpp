#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "==============================================" << std::endl;
	std::cout << "=============  Bob tax form  =================" << std::endl;
	std::cout << "==============================================" << std::endl;

	Bureaucrat bob("Bob", 50);
	Form contract("Contract", 45, 30);
	bob.signForm(contract);

	std::cout << "==============================================" << std::endl;
	std::cout << "=============  Anne and the fine  ============" << std::endl;
	std::cout << "==============================================" << std::endl;

	Bureaucrat anne("Anne", 87);
	Form fine("Fine", 90, 45);
	anne.signForm(fine);

	std::cout << "==============================================" << std::endl;
	std::cout << "=============  End of the story   ============" << std::endl;
	std::cout << "==============================================" << std::endl;

	return 0;
}
