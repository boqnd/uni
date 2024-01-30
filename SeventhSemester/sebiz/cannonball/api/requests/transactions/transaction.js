import stripe from 'stripe';

const stripeSecretKey = 'sk_test_51OX7G3DS0380Hgq2yjyzbvpdOgIFQO8Htci74k9Lo9Y5QUjsOYnLw0MxC78pa7stJ8IGkeHi2mLBjW8aiRSWJuTC00rbiQuUWg';
const stripeInstance = stripe(stripeSecretKey);

export let transactionRoute = '/transaction';

export async function transaction (req, res) {
  const { price } = req.body;
  const total = (price*100).toFixed(0);
  const paymentIntent = await stripeInstance.paymentIntents.create({
    amount: total,
    currency: 'usd',
  });

  res.json({ clientSecret: paymentIntent.client_secret });
};