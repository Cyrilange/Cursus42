let button = document.getElementById('btn');
const apiUrl = `https://weather-proxy.freecodecamp.rocks/api/current?lon=-4.4216&lat=36.7213`; // malaga

fetch(apiUrl)
  .then(response => response.json())
  .then(data => {
    const tempInCelsius = data.main.temp;
    let tempToShow = tempInCelsius;
    const weatherCondition = data.weather[0].main.toLowerCase();
    const iconUrl = data.weather[0].icon;
    let backgroundUrl = '';
    document.body.style.backgroundSize = ' 20%, cover';
    document.body.style.backgroundRepeat = 'no-repeat';
    document.body.style.backgroundPosition = ' 50% 95%'; 

    if (weatherCondition === 'clear') {
        backgroundUrl = 'url(clear-sky.jpg)';
    } else if (weatherCondition === 'rain') {
        backgroundUrl = 'url(rainy.jpg)';
    } else if (weatherCondition === 'clouds') {
        backgroundUrl = `url(${iconUrl})`;
    } else {
        backgroundUrl = 'url(default-weather.jpg)';
    }

    document.body.style.backgroundImage = backgroundUrl;

    button.addEventListener('click', function() {
        if (button.textContent === "CELC") {
            
            tempToShow = (tempInCelsius * 9/5) + 32; // Convert to Fahrenheit
            button.textContent = "FARH";
        } else {
            tempToShow = tempInCelsius; 
            button.textContent = "CELC";
        }

        document.getElementById('weather').textContent = `${tempToShow.toFixed(1)}°`;
    });
})
  .catch(error => console.error(error));
