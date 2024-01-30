import csv

def output_to_csv(media_list):
  with open('trending_media.csv', 'w', newline='', encoding='utf-8') as csvfile:
    writer = csv.writer(csvfile)
    writer.writerow(['title', 'raitng'])
    writer.writerows(media_list)