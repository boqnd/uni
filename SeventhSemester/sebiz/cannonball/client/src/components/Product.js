import React from 'react';

const Product = ({ product }) => {
  return (
    <div style={styles.product}>
      <img src={product.image} alt={product.name} style={styles.image} />
      <h3>{product.name}</h3>
      <p>{product.description}</p>
      <p>Price: ${product.price}</p>
      <button style={styles.button}>Add to Cart</button>
    </div>
  );
};

const styles = {
  product: {
    border: '1px solid #ddd',
    padding: '20px',
    borderRadius: '8px',
    margin: '20px',
    textAlign: 'center',
  },
  image: {
    maxWidth: '100%',
    marginBottom: '10px',
  },
  button: {
    padding: '10px',
    backgroundColor: '#3498db',
    color: 'white',
    borderRadius: '4px',
    cursor: 'pointer',
    border: 'none',
  },
};

export default Product;
