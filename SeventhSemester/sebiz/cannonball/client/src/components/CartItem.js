import React from 'react';

const CartItem = ({ item }) => {
  return (
    <div style={styles.cartItem}>
      <img src={item.image} alt={item.name} style={styles.image} />
      <div style={styles.itemInfo}>
        <h3>{item.name}</h3>
        <p>Quantity: x{item.quantity}</p>
        <p>Price: ${item.price}</p>
      </div>
    </div>
  );
};

const styles = {
  cartItem: {
    display: 'flex',
    alignItems: 'center',
    border: '1px solid #ddd',
    padding: '10px',
    borderRadius: '8px',
    marginBottom: '10px',
  },
  image: {
    maxWidth: '60px',
    marginRight: '10px',
  },
  itemInfo: {
    flexGrow: 1,
  },
};

export default CartItem;
