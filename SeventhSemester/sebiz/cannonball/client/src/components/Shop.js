import React, { useState, useEffect } from 'react';
import Product from './Product';
import Header from './Header';
import { useNavigate } from 'react-router-dom';


const Shop = ({user, logout, addToCart}) => {
  const navigate = useNavigate();
  useEffect(() => {
    if (!user) navigate('/login');
  }, [user, navigate])

  const [products, setProducts] = useState([]);

  useEffect(() => {
    const fetchProducts = async () => {
      try {
        // Fetch posts
        const productsResponse = await fetch('http://localhost:4000/products/getProducts', {
          method: 'POST',
          headers: {
            'Content-Type': 'application/json',
          },
          body: JSON.stringify({
            // Add any necessary parameters here
          }),
        });
        const productsData = await productsResponse.json();
        setProducts(productsData);
      } catch (error) {
        console.error('Error fetching posts:', error);
      }
    };

    fetchProducts();
  }, []);

  return (
    <div>
      <Header user={user} logout={logout} />
      <div style={styles.container}>
        <h2 style={styles.heading}>Shop</h2>
        {products.map(p => <Product product={p} addToCart={addToCart} /> )}
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
