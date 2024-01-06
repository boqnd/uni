import postsDao from "../../db/daos/postsDao.js";

export let getPostRoute = '/posts/getPost/:id';

export async function getPost (req, res) {
  const id = req.params['id'];
  const post = await postsDao?.getOne(id);
  res.send(post);
};