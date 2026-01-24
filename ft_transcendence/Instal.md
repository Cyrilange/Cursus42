
Frontend (Next.js / React)
│
├── Auth Web2 (JWT / OAuth)
│
├── UI Campagnes
│
├── Paiement (Web3 only here)
│     └── MetaMask / WalletConnect
│
Backend (NestJS)
│
├── Users
├── Campaigns
├── Updates / Comments
├── Notifications
├── Analytics
│
Blockchain
└── Smart Contract (paiements uniquement)


# FRONTEND — Next.js (React)
# why : React + routing integrated + SSR/SSG natif.
#  (SEO, perf,clean structure).
npx create-next-app frontend
cd frontend
npm run dev
cd ..

# BACKEND — Node.js + Express
# why : simple, light, full JS, ultra compatible with Next.js.
# API REST, auth web2, logique métier.
mkdir backend
cd backend
npm init -y
npm install express
touch index.js
node index.js
cd ..

# BLOCKCHAIN — Hardhat (Web3)
# why : standard for Ethereum.
# Tests, smart contracts, intégration easy with


 frontend.
mkdir blockchain
cd blockchain
npm init -y
npm install --save-dev hardhat
npx hardhat
