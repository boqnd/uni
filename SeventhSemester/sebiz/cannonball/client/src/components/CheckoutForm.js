// CheckoutForm.js
import React, { useState } from 'react';
import { CardElement, useStripe, useElements } from '@stripe/react-stripe-js';

const CheckoutForm = ({user, cartItems, handleCheckout}) => {
  const stripe = useStripe();
  const elements = useElements();
  const [orderDetails, setOrderDetails] = useState({
    name: '',
    email: '',
    address: '',
  });

  const handleChange = (e) => {
    setOrderDetails({
      ...orderDetails,
      [e.target.name]: e.target.value,
    });
  };

  const handleSubmit = async (event) => {
    event.preventDefault();

    if (!stripe || !elements) {
      // Stripe.js has not loaded yet
      return;
    }

    // Get a reference to a mounted CardElement
    const cardElement = elements.getElement(CardElement);

    // Use the card Element with other Stripe.js APIs
    const { token, error } = await stripe.createToken(cardElement);

    if (error) {
      console.error(error);
    } else {
      // Send the token and order details to your server
      console.log('Token:', token);
      console.log('Order Details:', orderDetails);

      const response = await fetch('http://localhost:4000/orders/createOrder', {
        method: 'POST',
        headers: {
          'Content-Type': 'application/json',
        },
        body: JSON.stringify({
            userId: user._id,
            products: cartItems,
            ...orderDetails
        }),
      });
      

      const payment = await fetch('http://localhost:4000/transaction', {
        method: 'POST',
        headers: {
          'Content-Type': 'application/json',
        },
        body: JSON.stringify({
          price: cartItems.reduce((total, item) => total + item.quantity*item.price, 0).toFixed(2)
        }),
      });

      if (response && payment) {
        handleCheckout();
      } else {
        console.log(response)
      }
    }
  };

  return (
    <form onSubmit={handleSubmit} style={styles.form}>
      <label style={styles.label}>Customer Name:</label>
      <input
        type="text"
        name="name"
        value={orderDetails.name}
        onChange={handleChange}
        style={styles.input}
        required
      />

      <label style={styles.label}>Email Address:</label>
      <input
        type="email"
        name="email"
        value={orderDetails.email}
        onChange={handleChange}
        style={styles.input}
        required
      />

      <label style={styles.label}>Shipping Address:</label>
      <input
        type="text"
        name="address"
        value={orderDetails.address}
        onChange={handleChange}
        style={styles.input}
        required
      />

      <label style={styles.label}>Card Details:</label>
      <CardElement style={styles.cardElement} />

      <button type="submit" disabled={!stripe} style={styles.submitButton}>
        Pay Now
      </button>
    </form>
  );
};

const styles = {
  form: {
    maxWidth: '400px',
    margin: 'auto',
  },
  label: {
    marginBottom: '5px',
    fontWeight: 'bold',
  },
  input: {
    padding: '10px',
    fontSize: '14px',
    marginBottom: '10px',
    width: '100%',
    border: '1px solid #ddd',
    borderRadius: '4px',
  },
  cardElement: {
    padding: '10px',
    fontSize: '14px',
    border: '1px solid #ddd',
    borderRadius: '4px',
  },
  submitButton: {
    marginTop: '10px',
    padding: '12px',
    backgroundColor: '#3498db',
    color: 'white',
    borderRadius: '4px',
    cursor: 'pointer',
    border: 'none',
    width: '100%',
  },
};

export default CheckoutForm;
