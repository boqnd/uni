import React, { useState } from 'react';

const Product = ({ product, addToCart }) => {
  const [quantity, setQuantity] = useState(1);

  const handleQuantityChange = (event) => {
    const newQuantity = parseInt(event.target.value, 10);
    setQuantity(newQuantity);
  };

  const incrementQuantity = () => {
    setQuantity((prevQuantity) => prevQuantity + 1);
  };

  const decrementQuantity = () => {
    if (quantity > 1) {
      setQuantity((prevQuantity) => prevQuantity - 1);
    }
  };

  return (
    <div style={styles.product}>
      <img src={product.image} alt={product.name} style={styles.image} />
      <h3>{product.name}</h3>
      <p>{product.description}</p>
      <p>Price: ${product.price}</p>
      <div style={styles.quantityContainer}>
        <label>
          Quantity:
          <input
            type="number"
            value={quantity}
            onChange={handleQuantityChange}
            style={styles.quantityInput}
          />
        </label>
        <button onClick={decrementQuantity} style={styles.quantityButton}>
          -
        </button>
        <button onClick={incrementQuantity} style={styles.quantityButton}>
          +
        </button>
      </div>
      <button
        style={styles.button}
        onClick={() => addToCart({ ...product, quantity })}
      >
        Add to Cart
      </button>
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
  quantityContainer: {
    marginTop: '10px',
    display: 'flex',
    alignItems: 'center',
  },
  quantityInput: {
    marginLeft: '5px',
    width: '50px',
    textAlign: 'center',
  },
  quantityButton: {
    marginLeft: '5px',
    padding: '5px',
    backgroundColor: '#3498db',
    color: 'white',
    borderRadius: '4px',
    cursor: 'pointer',
    border: 'none',
  },
  button: {
    padding: '10px',
    backgroundColor: '#3498db',
    color: 'white',
    borderRadius: '4px',
    cursor: 'pointer',
    border: 'none',
    marginTop: '10px',
  },
};

export default Product;
