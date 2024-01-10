import React, { useEffect } from 'react';
import Product from './Product';
import Header from './Header';
import { useNavigate } from 'react-router-dom';


const Shop = ({user, logout, addToCart}) => {
  // console.log(addToCart)

  const navigate = useNavigate();
  useEffect(() => {
    if (!user) navigate('/login');
  }, [user, navigate])

  const productData = {
    name: 'Example Product',
    description: 'This is an example product description.',
    price: 19.99,
    image: 'https://placekitten.com/300/200', // Replace with actual image URL
  };

  return (
    <div>
      <Header user={user} logout={logout} />
      <div style={styles.container}>
        <h2 style={styles.heading}>Shop</h2>
        <Product product={productData} addToCart={addToCart} />
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

export default Shop;
