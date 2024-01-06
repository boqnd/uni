import React, {useState} from 'react';
import { BrowserRouter as Router, Route, Routes } from 'react-router-dom';
import Login from './components/Login';
import Home from './components/Home';

const App = () => {
  const [isLoggedIn, setLoggedIn] = useState(false);

  const login = () => {
    setLoggedIn(true);
  }

  // const logout = () => {
  //   setLoggedIn(false);
  // }

  console.log(isLoggedIn)
  return (
    <Router>
      <Routes>
        <Route path="/" element={<Home isLoggedIn={isLoggedIn}/>} />
        <Route path="/login" element={<Login login={login} />} />
      </Routes>
    </Router>
  );
};

export default App;
