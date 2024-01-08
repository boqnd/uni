import React, {useState} from 'react';
import { BrowserRouter as Router, Route, Routes } from 'react-router-dom';
import Login from './components/Login';
import Home from './components/Home';
import NewPost from './components/NewPost';

const App = () => {
  const [user, setUser] = useState(null);

  const login = (_user) => {
    setUser(_user);
  }

  // const logout = () => {
  //   setLoggedIn(false);
  // }

  // console.log(isLoggedIn)
  return (
    <Router>
      <Routes>
        <Route path="/" element={<Home user={user}/>} />
        <Route path="/new-post" element={<NewPost user={user}/>} />

        <Route path="/login" element={<Login login={login} />} />
      </Routes>
    </Router>
  );
};

export default App;
