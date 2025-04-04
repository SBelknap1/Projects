import requests

def get_weather(api_key, city):
    base_url = "http://api.openweathermap.org/data/2.5/weather"
    params = {
        "q": city,
        "appid": api_key,
        "units": "metric"  # Use "imperial" for Fahrenheit
    }
    try:
        response = requests.get(base_url, params=params)
        data = response.json()
        if response.status_code == 200:
            print(f"\nWeather in {city.capitalize()}:")
            print(f"Temperature: {data['main']['temp']}°C")
            print(f"Humidity: {data['main']['humidity']}%")
            print(f"Condition: {data['weather'][0]['description'].capitalize()}")
        else:
            print(f"Error: {data['message']}")
    except Exception as e:
        print("An error occurred:", e)

def main():
    api_key = "df8e1fa5c12e2980d294ddb97d4a209a"  # Your API key
    print("Welcome to the Python Weather Application!")
    while True:
        city = input("\nEnter city name to get weather information (or type 'exit' to quit): ")
        if city.lower() == "exit":
            print("Exiting the Weather Application. Stay safe!")
            break
        get_weather(api_key, city)

if __name__ == "__main__":
    main()
