def sort_by_rating(media_list):
    return sorted(media_list, key=lambda x: x[1], reverse=True)