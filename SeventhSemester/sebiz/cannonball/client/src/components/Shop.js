import React, { useEffect } from 'react';
import Product from './Product';
import Header from './Header';
import { useNavigate } from 'react-router-dom';


const Shop = ({user, logout, addToCart}) => {
  const navigate = useNavigate();
  useEffect(() => {
    if (!user) navigate('/login');
  }, [user, navigate])

  const productData = {
    name: 'Устройство за верифициране на време',
    description: 'С това устройство ще можете да публикувате верифицирани времена и всички потребители ще могат да бъдат сигурни че казвате истината',
    price: 19.99,
    image: 'https://karaokeuk-static.myshopblocks.com/images/2023/02/contain/256x256/67dbbec796f07fd64d81f4059608b064.jpg',
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
