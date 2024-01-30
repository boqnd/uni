import sys
from package import get_trending, output_to_csv, output_to_json, sort_by_rating

if __name__ == "__main__":
  if len(sys.argv) != 4:
    sys.exit(1)

  media_type, time_window, output_format = sys.argv[1], sys.argv[2], sys.argv[3]

  trending_media = get_trending.get_trending(media_type, time_window)
  media = 'title' if media_type == 'movie' else 'name'
  sorted_media = sort_by_rating.sort_by_rating([(movie[media], movie['vote_average']) for movie in trending_media])

  print(sorted_media)
  if output_format == 'csv':
    output_to_csv.output_to_csv(sorted_media)
  elif output_format == 'json':
    output_to_json.output_to_json(sorted_media)
  else:
    print("wrong output format")
    sys.exit(1)
