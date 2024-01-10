import React from 'react';
import ReactDOM from 'react-dom/client';
import { Elements } from '@stripe/react-stripe-js';
import { loadStripe } from '@stripe/stripe-js';
import App from './App';

const stripePromise = loadStripe('pk_test_51OX7G3DS0380Hgq27JkEcF7SNQkLpLbq7cCVXC2DwgHgUXihggZwRsTXRnU8dH9VyaUVFr04uNoUhmzN0JUvvC6q00VZ2OkHlj');

const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(
  <Elements stripe={stripePromise}>
    <App />
  </Elements>,
);
