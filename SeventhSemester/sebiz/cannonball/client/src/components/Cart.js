// Cart.js
import React, { useState, useEffect } from 'react';
import { useNavigate } from 'react-router-dom';
import Header from './Header';
import CartItem from './CartItem';
import CheckoutForm from './CheckoutForm';

const Cart = ({ user, logout, cartItems }) => {
  const navigate = useNavigate();
  const [isPaid, setIsPaid] = useState(false);

  useEffect(() => {
    if (!user) navigate('/login');
  }, [user, navigate]);

  const handleCheckout = () => {
    setIsPaid(true);
  };

  return (
    <div>
      <Header user={user} logout={logout} />
      <div style={styles.container}>
        <h2 style={styles.heading}>Shopping Cart</h2>
        {cartItems.map((item, index) => (
          <CartItem key={index} item={item} />
        ))}
        {!isPaid ? (
          <div style={styles.paymentSection}>
            <h3>Payment Details</h3>
            <CheckoutForm />
          </div>
        ) : (
          <p style={styles.paymentSuccess}>Payment successful! Your order is being processed.</p>
        )}
      </div>
    </div>
  );
};

const styles = {
  container: {
    padding: '20px',
    backgroundColor: '#f5f5f5',
    color: '#333',
    textAlign: 'center',
  },
  heading: {
    fontSize: '24px',
    fontWeight: 'bold',
    marginBottom: '20px',
  },
  paymentSection: {
    marginTop: '20px',
  },
  checkoutButton: {
    padding: '12px',
    backgroundColor: '#3498db',
    color: 'white',
    borderRadius: '4px',
    cursor: 'pointer',
    border: 'none',
    marginTop: '10px',
  },
  paymentSuccess: {
    fontSize: '18px',
    color: '#27ae60',
  },
};

export default Cart;
