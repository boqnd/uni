import React, { useEffect } from 'react';
import { useNavigate } from 'react-router-dom';

const Home = ({isLoggedIn}) => {
  const navigate = useNavigate();
  useEffect(() => {
    if (!isLoggedIn) navigate('/login');
  }, [isLoggedIn, navigate])

  return (
    <div style={styles.container}>
      <h2 style={styles.heading}>Welcome to My App</h2>
      <p style={styles.paragraph}>
        This is a simple home page. Customize it based on your project's
        requirements.
      </p>
    </div>
  )
};

const styles = {
  container: {
    maxWidth: '600px',
    margin: 'auto',
    padding: '20px',
    border: '1px solid #ccc',
    borderRadius: '8px',
    marginTop: '50px',
    textAlign: 'center',
  },
  heading: {
    color: '#333',
  },
  paragraph: {
    color: '#666',
  },
};

export default Home;
