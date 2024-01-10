import React, {useState} from 'react';
import { BrowserRouter as Router, Route, Routes } from 'react-router-dom';
import Login from './components/Login';
import Home from './components/Home';
import NewPost from './components/NewPost';
import Shop from './components/Shop';
import Cart from './components/Cart';

const App = () => {
  const [user, setUser] = useState(null);
  const [cart, setCart] = useState([]);

  const login = (_user) => {
    setUser(_user);
  }

  const logout = () => {
    setUser(null);
  }

  const addToCart = (item) => {
    setCart(oldCart => [...oldCart, item])
  }

  return (
    <Router>
      <Routes>
        <Route path="/" element={<Home user={user} logout={logout} />} />
        <Route path="/new-post" element={<NewPost user={user} logout={logout}/>} />
        <Route path="/shop" element={<Shop user={user} logout={logout} addToCart={addToCart} />} />
        <Route path="/cart" element={<Cart user={user} logout={logout} cartItems={cart} />} />

        <Route path="/login" element={<Login login={login} />} />
      </Routes>
    </Router>
  );
};

export default App;
