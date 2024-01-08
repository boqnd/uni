import React, { useEffect } from 'react';
import { useNavigate } from 'react-router-dom';
import Feed from './Feed';
import Header from './Header';

const Home = ({user}) => {
  const navigate = useNavigate();
  useEffect(() => {
    if (!user) navigate('/login');
  }, [user, navigate])

  return (
    <div>
      <Header user={user}/>
      <Feed />
    </div>
  );
};

export default Home;
