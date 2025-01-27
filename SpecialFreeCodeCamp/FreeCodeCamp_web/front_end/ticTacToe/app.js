const board = document.getElementsByClassName('boardGame');
let turn = document.getElementById('turn');
const squares = document.getElementsByClassName('squares')
const player = ['X', 'O'];
let currentPlayer = player[0];

const winning_combinations = [
    [0, 1, 2],
    [3, 4, 5],
    [6, 7, 8],
    [0, 3, 6],
    [1, 4, 7],
    [2, 5, 8],
    [0, 4, 8],
    [2, 4, 6]
]

function getWin(currentPlayer) {
    for (let i = 0; i < winning_combinations.length; i++) {
        const [a, b, c] = winning_combinations[i];
        if (squares[a].textContent == currentPlayer && 
            squares[b].textContent == currentPlayer && 
            squares[c].textContent == currentPlayer) {
            return true;
        }
    }
    return false;
}

function getEqual(currentPlayer) {
    for (let i = 0; i < winning_combinations.length; i++) {
        if (squares[i].textContent === ' ') {
            return false;
        }
    }
    return true;
}

function choosePlayer() {

}

function restart() {
    
}