'use client';
import { useRouter } from "next/navigation";


export default function SignUpPage() {

	const router = useRouter();
  return (
    <div className="flex min-h-screen items-center justify-center bg-black text-white">
      <main className="flex flex-col items-center gap-8 px-8">

        <h1 className="    font-bold text-center
          text-4xl sm:text-6xl md:text-8xl lg:text-9xl">Sign Up</h1>
        <p className="text-gray-400 text-center">Choose a method to create your account</p>

        <div className="flex flex-col gap-4 ">
          {/* Fake Email / Password */}
          <button className="cursor-pointer px-6 py-3 bg-gray-900 rounded hover:bg-gray-800">
            Sign up with Email
          </button>

          {/* Google */}
          <button className="cursor-pointer px-6 py-3 bg-gray-900 rounded hover:bg-gray-800">
            Sign up with Google
          </button>

          {/* GitHub */}
          <button className="cursor-pointer px-6 py-3 bg-gray-900 rounded hover:bg-gray-800">
            Sign up with GitHub
          </button>
		  <button  onClick={() => router.push("/")}
            className="cursor-pointer px-6 py-3 bg-gray-900 rounded hover:bg-gray-800">
            Back
			
			
          </button>
        </div>

      </main>
    </div>
  );
}
