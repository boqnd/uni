import React, { useEffect } from 'react';
import { useNavigate } from 'react-router-dom';
import Feed from './Feed';
import Header from './Header';

const Home = ({user, logout}) => {
  const navigate = useNavigate();
  useEffect(() => {
    if (!user) navigate('/login');
  }, [user, navigate])

  return (
    <div>
      <Header user={user} logout={logout} />
      <Feed />
    </div>
  );
};

export default Home;
