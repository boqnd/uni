// Feed.js
import React, { useState, useEffect } from 'react';

const Feed = () => {
  const [posts, setPosts] = useState([]);

  useEffect(() => {
    const fetchPosts = async () => {
      try {
        // Fetch posts
        const postsResponse = await fetch('http://localhost:4000/posts/getPosts', {
          method: 'POST',
          headers: {
            'Content-Type': 'application/json',
          },
          body: JSON.stringify({
            // Add any necessary parameters here
          }),
        });
        const postsData = await postsResponse.json();

        // Fetch user and trip information for each post
        const postsWithDetails = await Promise.all(
          postsData.map(async (post) => {
            const userResponse = await fetch(`http://localhost:4000/auth/getUser/${post.userId}`, {
              method: 'POST',
              headers: {
                'Content-Type': 'application/json',
              },
            });
            const userData = await userResponse.json();

            const tripResponse = await fetch(`http://localhost:4000/trips/getTrip/${post.tripId}`, {
              method: 'POST',
              headers: {
                'Content-Type': 'application/json',
              },
            });
            const tripData = await tripResponse.json();

            return {
              ...post,
              user: userData, // Attach user information
              trip: tripData, // Attach trip information
            };
          })
        );

        setPosts(postsWithDetails);
      } catch (error) {
        console.error('Error fetching posts:', error);
      }
    };

    fetchPosts();
  }, []);

  return (
    <div>
      <h2>Feed</h2>
      <div style={styles.feedContainer}>
        {posts.map((post) => (
          <div key={post._id} style={styles.postCard}>
            {post.approved && <div style={styles.approvedBadge}>Approved</div>}
            <p style={styles.postUser}>User: {post.user.username}</p>
            <p style={styles.postTrip}>Trip: {post.trip.startLocation} {"->"} {post.trip.endLocation}</p>
            <p style={styles.postTime}>Time: {post.tripTime}</p>
            <p style={styles.postComment}>Comment: {post.comment}</p>
          </div>
        ))}
      </div>
    </div>
  );
};

const styles = {
  feedContainer: {
    display: 'grid',
    gridTemplateColumns: 'repeat(auto-fill, minmax(300px, 1fr))',
    gap: '20px',
  },
  postCard: {
    position: 'relative',
    borderRadius: '10px',
    boxShadow: '0 0 10px rgba(0, 0, 0, 0.1)',
    padding: '20px',
    backgroundColor: '#fff',
    transition: 'transform 0.2s ease-in-out',
    cursor: 'pointer',
    '&:hover': {
      transform: 'scale(1.05)',
    },
  },
  approvedBadge: {
    position: 'absolute',
    top: '10px',
    right: '10px',
    backgroundColor: '#3498db',
    color: '#fff',
    padding: '5px 10px',
    borderRadius: '5px',
    fontWeight: 'bold',
  },
  postUser: {
    margin: 0,
    fontWeight: 'bold',
  },
  postTrip: {
    margin: 0,
  },
  postTime: {
    margin: 0,
  },
  postComment: {
    margin: 0,
  },
};

export default Feed;
