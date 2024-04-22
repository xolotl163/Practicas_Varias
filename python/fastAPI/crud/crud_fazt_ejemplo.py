
from fastapi import FastAPI, HTTPException
from pydantic import BaseModel
from typing import Text, Optional
from datetime import datetime
from uuid import uuid4 as uuid

app = FastAPI()

#Post Modelclass 
class Post(BaseModel):
    id: Optional[str]
    title: str
    author: str
    content: Text
    created_at: Optional[datetime]
    published_at: Optional[datetime] = None
    published: Optional[bool] = False

posts = []

@app.get('/')
def read_root():
    return {"welcome": "welcome to my RestAPI"}

@app.get('/posts')
def get_posts():
    return posts

@app.post('/posts')
def save_post(post: Post):
    post.id = str(uuid())
    posts.append( post.dict() )
    return posts[-1]

@app.get('/posts/{post_id}')
def get_post(post_id: str):
    for post in posts:
        if post["id"] == post_id:
            return post
    raise HTTPException(status_code=404, detail="post not found")

@app.delete("/posts/{post_id}")
def delete_post(post_id: str):
    for index, post in enumerate(posts):
        if post["id"] == post_id:
            posts.pop(index)
            return {"message": "se ha eliminado la publicación"}
    raise HTTPException(status_code=404, detail="post not found")

@app.put("/posts/{post_id}")
def update_post(post_id: str, updatedPost: Post):
    for index, post in enumerate(posts):
        if post["id"] == post_id:
            post[index]["title"] = str(updatedPost.title)
            post[index]["content"] = str(updatedPost.content)
            post[index]["author"] = updatedPost.author
            return {"message": "Post has been updated"}
    raise HTTPException(status_code=404, detail="post not found")
        