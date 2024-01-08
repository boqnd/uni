import React from 'react';
import { Link } from 'react-router-dom';
import { FaPlus, FaShoppingCart, FaSearch, FaSignOutAlt, FaUser, FaRss } from 'react-icons/fa';

const Header = ({user, logout}) => {
  return (
    <div style={styles.header}>
      <div style={styles.logo}>Cannonball Bulgaria</div>
      {user && <div>{user.username}</div>}
      <div style={styles.options}>
        <Link to="/new-post" style={styles.option}>
          <FaPlus style={styles.icon} />
          New Post
        </Link>
        <Link to="/shop" style={styles.option}>
          <FaShoppingCart style={styles.icon} />
          Shop
        </Link>
        <Link to="/cart" style={styles.option}>
          <FaShoppingCart style={styles.icon} />
          Cart
        </Link>
        <div style={styles.option}>
          <FaSearch style={styles.icon} />
          Search
        </div>
        <div style={styles.option}>
          <FaUser style={styles.icon} />
          Profile
        </div>
        <Link to="/" style={styles.option}>
          <FaRss style={styles.icon} />
          Feed
        </Link>
        <div style={styles.option} onClick={logout}>
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
    flexDirection: 'row', // Set to 'row' for horizontal layout
  },
  logo: {
    fontSize: '24px',
    fontWeight: 'bold',
  },
  options: {
    display: 'flex',
    flexDirection: 'row', // Set to 'row' for horizontal layout
    alignItems: 'center',
  },
  option: {
    display: 'flex',
    alignItems: 'center',
    cursor: 'pointer',
    marginRight: '20px',
    color: 'white',
    textDecoration: 'none', // Remove underline
  },
  icon: {
    marginRight: '5px',
    color: 'white'
  },
};

export default Header;
