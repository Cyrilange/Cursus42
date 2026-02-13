'use client';

import { useState, useEffect } from 'react';
import Navbar from './Navbar';

export default function NavbarWrapper() {
  const [isLoggedIn, setIsLoggedIn] = useState(false);

  useEffect(() => {
    const token = localStorage.getItem('token');
    setIsLoggedIn(!!token);
  }, []);

  return <Navbar isLoggedIn={isLoggedIn} />;
}
