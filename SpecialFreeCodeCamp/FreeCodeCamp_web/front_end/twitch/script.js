const urlTc = "https://twitch-proxy.freecodecamp.rocks/helix";
let users = document.getElementById('user-list');
let channels = ["ESL_SC2", "OgamingSC2", "cretetion", "freecodecamp", "storbeck", "habathcx", "RobotCaleb", "noobs2ninjas"];

async function getUsers() {
    for (const channel of channels) {
        try {
            let response = await fetch(`${urlTc}/streams?user_login=${channel}`);
            let data = await response.json();
            let li = document.createElement('li');
            if (data.data.length > 0) {
                let stream = data.data[0];
                li.innerHTML = `
                <a href="https://www.twitch.tv/${channel}" target="_blank">
                ${channel} <span style="color: green;">[LIVE]</span>
            </a>
            <p>Game : ${stream.game_name}</p>
            <p>Stream : ${stream.title}</p>
        `;
            } else {
                li.innerHTML = `
                <a href="https://www.twitch.tv/${channel}" target="_blank">
                ${channel} <span style="color: red;">[OFFLINE]</span>
            </a>
        `;
            }
            users.appendChild(li);
        } catch (error){
            console.error("error"); };
        } }
        



getUsers();