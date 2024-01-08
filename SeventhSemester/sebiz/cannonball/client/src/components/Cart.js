import React, { useState, useEffect } from 'react';
import CartItem from './CartItem';
import { useNavigate } from 'react-router-dom';
import Header from './Header';


const Cart = ({user, logout}) => {
  const navigate = useNavigate();
  useEffect(() => {
    if (!user) navigate('/login');
  }, [user, navigate])

  // Simulated cart items (replace with actual cart data)
  const [cartItems, setCartItems] = useState([
    {
      name: 'Example Product 1',
      price: 19.99,
      image: 'https://placekitten.com/80/80', // Replace with actual image URL
    },
    {
      name: 'Example Product 2',
      price: 29.99,
      image: 'https://placekitten.com/80/80', // Replace with actual image URL
    },
  ]);

  return (
    <div>
      <Header user={user} logout={logout} />
      <div style={styles.container}>
        <h2 style={styles.heading}>Shopping Cart</h2>
        {cartItems.map((item, index) => (
          <CartItem key={index} item={item} />
        ))}
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
};

export default Cart;
