// components/Header.js

import React from 'react';
import { FaPlus, FaShoppingCart, FaSearch, FaSignOutAlt } from 'react-icons/fa'; // Import icons from react-icons library

const Header = () => {
  return (
    <div style={styles.header}>
      <div style={styles.logo}>Cannonball Bulgaria</div>
      <div style={styles.options}>
        <div style={styles.option}>
          <FaPlus style={styles.icon} />
          New Post
        </div>
        <div style={styles.option}>
          <FaShoppingCart style={styles.icon} />
          Shop
        </div>
        <div style={styles.option}>
          <FaShoppingCart style={styles.icon} />
          Cart
        </div>
        <div style={styles.option}>
          <FaSearch style={styles.icon} />
          Search Bar
        </div>
        <div style={styles.option}>
          <FaSignOutAlt style={styles.icon} />
          Logout
        </div>
      </div>
    </div>
  );
};

const styles = {
  header: {
    display: 'flex',
    justifyContent: 'space-between',
    alignItems: 'center',
    padding: '10px',
    backgroundColor: '#333',
    color: 'white',
  },
  logo: {
    fontSize: '20px',
    fontWeight: 'bold',
  },
  options: {
    display: 'flex',
    gap: '20px',
  },
  option: {
    display: 'flex',
    alignItems: 'center',
    cursor: 'pointer',
  },
  icon: {
    marginRight: '5px',
  },
};

export default Header;
