import json

def output_to_json(media_list):
    with open('trending_media.json', 'w', encoding='utf-8') as jsonfile:
        json.dump(media_list, jsonfile, ensure_ascii=False, indent=2)