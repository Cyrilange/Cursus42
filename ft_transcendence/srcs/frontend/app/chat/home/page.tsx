'use client';

import Navbar from "@/app/components/Navbar";

export default function ChatPage() {
  return (
    <div>
      {/* On simule l’utilisateur connecté */}
      <Navbar isLoggedIn={true} />
      <main className="p-8">
        <h1 className="text-3xl font-bold">Chat Page</h1>
        <p>Bienvenue dans le chat, utilisateur connecté !</p>
      </main>
    </div>
  );
}
