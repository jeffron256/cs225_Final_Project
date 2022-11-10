import json

if __name__ == "__main__":
    data = {}

    filepath = "GetStops.json"
    with open(filepath, 'r') as f:
        data = json.load(f)

    stops = data["stops"]
    print("Number of stops:", len(stops))

    for stop in stops:
        print(stop["stop_name"])