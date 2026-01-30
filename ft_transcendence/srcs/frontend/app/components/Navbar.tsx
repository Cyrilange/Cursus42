'use client';

import Link from 'next/link';

interface NavbarProps {
  isLoggedIn: boolean;
}

export default function Navbar({ isLoggedIn }: NavbarProps) {
  if (!isLoggedIn) return null;

  return (
    <nav className="w-full bg-gray-900 text-white px-4 py-2 flex justify-between items-center">
      <div className="text-xl font-bold"><Link href="/">ft_transcendence</Link></div>
      <ul className="flex gap-4">
        <li><Link href="/campaigns">Campaigns</Link></li>
        <li><Link href="/chat">Chat</Link></li>
        <li><Link href="/settings">Settings</Link></li>
        <li><Link href="/auth/logout">Logout</Link></li>
      </ul>
    </nav>
  );
}