import React, { useEffect } from 'react';
import { useNavigate } from 'react-router-dom';
import Feed from './Feed';
import Header from './Header';

const Home = ({isLoggedIn}) => {
  const navigate = useNavigate();
  useEffect(() => {
    if (!isLoggedIn) navigate('/login');
  }, [isLoggedIn, navigate])

  return (
    <div>
      <Header />
      <Feed />
    </div>
  );
};

export default Home;
