import requests
import json

def get_trending(media_type, time_window):
  url = f"https://api.themoviedb.org/3/trending/{media_type}/{time_window}"
  token = "eyJhbGciOiJIUzI1NiJ9.eyJhdWQiOiJhZDVhNDU4YzljZmMxODdjZThlMDdhM2ZiYTU1MjE0YyIsInN1YiI6IjY1NzRkNzA2ZTkzZTk1MDExZDRlMmM2MiIsInNjb3BlcyI6WyJhcGlfcmVhZCJdLCJ2ZXJzaW9uIjoxfQ.MsO7CO9573rr8rTEczZJ4PW6dnVX9xuU2OUNOcaHEts"
  headers = {"accept": "application/json", "Authorization": f"Bearer {token}"}
  response = requests.get(url, headers=headers)

  formated = json.loads(response.content)

  return formated["results"]