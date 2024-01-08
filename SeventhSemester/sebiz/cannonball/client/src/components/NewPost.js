import React, { useState, useEffect } from 'react';
import Header from './Header'; // Import the Header component
import { useNavigate } from 'react-router-dom';

const NewPost = ({user, logout}) => {
  const navigate = useNavigate();
  useEffect(() => {
    if (!user) navigate('/login');
  }, [user, navigate])


  const [postData, setPostData] = useState({
    userId: user?._id,
    startLocation: '',
    endLocation: '',
    tripTime: '',
    comment: '',
    approved: true,
  });

  const handleInputChange = (e) => {
    const { name, value } = e.target;
    setPostData((prevData) => ({
      ...prevData,
      [name]: value,
    }));
  };

  const handleSubmit = async (e) => {
    e.preventDefault();
    try {
      // Make a POST request to save the new post
      const response = await fetch('http://localhost:4000/posts/createPost', {
        method: 'POST',
        headers: {
          'Content-Type': 'application/json',
        },
        body: JSON.stringify(postData),
      });

      // Handle the response accordingly
      console.log('New post created:', response);

      if (response.ok) {
        console.log('New post created successfully');
        // Redirect to the feed page
        navigate('/');
      } else {
        console.error('Failed to create a new post:', response.statusText);
        // Handle the error as needed
      }
    } catch (error) {
      console.error('Error creating a new post:', error);
    }
  };

  return (
    <div>
      <Header user={user} logout={logout} />
      <div style={styles.container}>
        <h2 style={styles.heading}>Create a New Post</h2>
        <div style={styles.postCard}>
          <form onSubmit={handleSubmit} style={styles.form}>
            <label style={styles.label}>Start Location:</label>
            <input
              type="text"
              name="startLocation"
              value={postData.startLocation}
              onChange={handleInputChange}
              style={styles.input}
            />
            <label style={styles.label}>End Location:</label>
            <input
              type="text"
              name="endLocation"
              value={postData.endLocation}
              onChange={handleInputChange}
              style={styles.input}
            />
            <label style={styles.label}>Trip Time:</label>
            <input
              type="text"
              name="tripTime"
              value={postData.tripTime}
              onChange={handleInputChange}
              style={styles.input}
            />
            <label style={styles.label}>Comment:</label>
            <textarea
              name="comment"
              value={postData.comment}
              onChange={handleInputChange}
              style={styles.textarea}
            />
            <button type="submit" style={styles.button}>
              Create Post
            </button>
          </form>
        </div>
      </div>
    </div>
  );
};

const styles = {
  container: {
    padding: '20px',
    backgroundColor: '#f5f5f5',
    color: '#333',
    maxWidth: '400px',
    margin: 'auto',
  },
  heading: {
    fontSize: '24px',
    fontWeight: 'bold',
    marginBottom: '20px',
    textAlign: 'center',
  },
  postCard: {
    borderRadius: '8px',
    boxShadow: '0 0 10px rgba(0, 0, 0, 0.1)',
    padding: '20px',
    backgroundColor: '#fff',
  },
  form: {
    display: 'flex',
    flexDirection: 'column',
  },
  label: {
    marginBottom: '5px',
    fontWeight: 'bold',
  },
  input: {
    padding: '10px',
    fontSize: '14px',
    marginBottom: '10px',
    border: '1px solid #ddd',
    borderRadius: '4px',
  },
  textarea: {
    padding: '10px',
    fontSize: '14px',
    minHeight: '80px',
    marginBottom: '10px',
    border: '1px solid #ddd',
    borderRadius: '4px',
  },
  button: {
    padding: '12px',
    backgroundColor: '#3498db',
    color: 'white',
    borderRadius: '4px',
    cursor: 'pointer',
    border: 'none',
  },
};

export default NewPost;
