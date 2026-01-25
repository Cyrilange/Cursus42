

export default function Home() {
  return (
    <div className="flex min-h-screen items-center justify-center bg-black text-white font-sans">
      <main className="
        flex min-h-screen w-full max-w-5xl flex-col items-center justify-center
        gap-6 px-4 sm:px-8 md:px-16
      ">

        <h1 className="
          font-bold text-center
          text-4xl sm:text-6xl md:text-8xl lg:text-9xl
        ">
          ft_transcendence
        </h1>

        <h2 className="
          text-center text-gray-300
          text-base sm:text-lg md:text-2xl lg:text-3xl
          max-w-2xl
        ">
          The crowdfunding platform mixing Web2 for accessibility and Web3 for security
        </h2>

        <ul className="
          flex flex-col sm:flex-row gap-4 sm:gap-6
          text-base sm:text-lg
        ">
          <li className="cursor-pointer hover:text-gray-400">
          <a href="./auth/signin">Sign-in</a>
          </li>
          <li className="cursor-pointer hover:text-gray-400">
          <a href="/auth/signup">Sign-up</a>
          </li>
        </ul>

      </main>
    </div>
  );
}


