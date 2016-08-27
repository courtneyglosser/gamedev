// Script for tile filling game


var canvas = document.getElementById("myCanvas");
var ctx = canvas.getContext("2d");

var gameState = "active"


var clickX = 0
var clickY = 0

var red = 0
var green = 0
var blue = 255
var color = "rgba(" + red + "," + green + "," + blue + ", 1)"

var leftMargin = 250
var topMargin = 40
var boardWidth = 460
var boardHeight = 460

var buttonSpacer = 100
var buttonWidth = (boardWidth - buttonSpacer) / 3
var buttonHeight = buttonWidth / 3

var numColumns = 3
var numRows = 3

var score = numColumns * numRows

red = 255
var color1 = "rgba(" + red + "," + green + "," + blue + ", 1)"
green = 255
var color2 = "rgba(" + red + "," + green + "," + blue + ", 1)"
red = 0
var color3 = "rgba(" + red + "," + green + "," + blue + ", 1)"
red = 255
blue = 0
var color4 = "rgba(" + red + "," + green + "," + blue + ", 1)"
red = 0
green = 0
blue = 255
var color5 = "rgba(" + red + "," + green + "," + blue + ", 1)"
red = 255
blue = 0
var color6 = "rgba(" + red + "," + green + "," + blue + ", 1)"
var buttonColors = []

buttonColors.push(color1)
buttonColors.push(color2)
buttonColors.push(color3)
buttonColors.push(color4)
buttonColors.push(color5)
buttonColors.push(color6)

var buttons = []
var button1 = {
    leftMargin: leftMargin,
    topMargin: (topMargin + boardHeight + buttonSpacer / 4),
    color: buttonColors[0]
}
var button2 = {
    leftMargin: leftMargin + buttonWidth + buttonSpacer/2,
    topMargin: (topMargin + boardHeight + buttonSpacer / 4),
    color: buttonColors[1]
}
var button3 = {
    leftMargin: leftMargin + (buttonWidth + buttonSpacer/2) * 2,
    topMargin: (topMargin + boardHeight + buttonSpacer / 4),
    color: buttonColors[2]
}
var button4 = {
    leftMargin: leftMargin,
    topMargin: (topMargin + boardHeight + buttonHeight + (buttonSpacer / 4)*2),
    color: buttonColors[3]

}
var button5 = {
    leftMargin: leftMargin + buttonWidth + buttonSpacer/2,
    topMargin: (topMargin + boardHeight + buttonHeight + (buttonSpacer / 4)*2),
    color: buttonColors[4]
}
var button6 = {
    leftMargin: leftMargin + (buttonWidth + buttonSpacer/2) * 2,
    topMargin: (topMargin + boardHeight + buttonHeight + (buttonSpacer / 4)*2),
    color: buttonColors[5]
}

buttons.push(button1)
buttons.push(button2)
buttons.push(button3)
buttons.push(button4)
buttons.push(button5)
buttons.push(button6)


var tileWidth = boardWidth / numColumns
var tileHeight = boardHeight / numRows
var boardTiles = []

for(var i = 0; i < numRows; i++) {
    for (var j = 0; j < numColumns; j++) {
        boardTiles.push({
            leftMargin: leftMargin + j * tileWidth,
            topMargin: topMargin + i * tileHeight,
            color: buttonColors[getRandomInt(0, 5)]
        })
    }
}

/**
 * Returns a random integer between min (inclusive) and max (inclusive)
 * Using Math.round() will give you a non-uniform distribution!
 */
function getRandomInt(min, max) {
    return Math.floor(Math.random() * (max - min + 1)) + min;
}

function drawScore() {
    ctx.font = "16px Arial";
    ctx.fillStyle = "#0095DD";
    ctx.fillText("Score: "+score, 8, 20);
}


function drawBoard() {
    boardTiles.forEach(function(v, k) {
        ctx.beginPath();
        ctx.rect(v.leftMargin, v.topMargin, tileWidth, tileHeight)
        ctx.fillStyle = v.color
        ctx.fill();
        ctx.closePath();
    })
}

function drawButtons() {

    buttons.forEach(function (v, k) {
        ctx.beginPath()
        ctx.rect(v.leftMargin, v.topMargin, buttonWidth, buttonHeight)
        ctx.fillStyle = v.color
        ctx.fill();
        ctx.closePath() 
    })
   
}

function drawWin() {
    ctx.font = "26px Arial";
    ctx.fillStyle = "#0095DD";
    ctx.fillText("Winner! ", canvas.width / 2 - 20, canvas.height / 2);
}

function drawLose() {
    ctx.font = "26px Arial";
    ctx.fillStyle = "#0095DD";
    ctx.fillText("Loser :( ", canvas.width / 2 - 20, canvas.height / 2);
}

function draw() {
    // drawing code
    ctx.clearRect(0, 0, canvas.width, canvas.height)

    if (gameState == "active") {

        drawBoard()
        drawButtons()

        drawScore()
    }
    else if (gameState == "win") {
        drawWin()
    }
    else if (gameState == "lose") {
        drawLose()
    }

}

function mouseDownHandler(e) {
    var BB=canvas.getBoundingClientRect();

    var relativeX = e.clientX - BB.left;
    var relativeY = e.clientY - BB.top;

    clickX = relativeX
    clickY = relativeY

    buttonPressDetection()

    draw()
}

function buttonPressDetection() {
    buttons.forEach(function(v, k) {
        if (clickX > v.leftMargin && clickX < v.leftMargin + buttonWidth &&
            clickY > v.topMargin && clickY < v.topMargin + buttonHeight) {

            registerClick(k)
        }

    })
}

function registerClick(idx) {
    var tiles = getArrayOfMatchingTiles()

    //ASSERT:  Clicked button[idx].  Set color to match
    tiles.forEach(function(v, k) {
        boardTiles[v].color = buttons[idx].color
    })

    score--

    if (score < 1) {
        // Loser :(
        gameState = "lose"
    }
    else {
        tiles = getArrayOfMatchingTiles()
        if (boardTiles.length == tiles.length) {
            // Winner!!
            gameState = "win"
        }
    }
}

function getArrayOfMatchingTiles() {

    // Start at boardTiles[0]
    var i = 0
    var rtn = [i]
    var clr = boardTiles[0].color

    rtn = findNeighbors(rtn, i, clr)


    uniqueArray = rtn.filter(function(item, pos, self) {
        return self.indexOf(item) == pos;
    })


    return uniqueArray
}

function findNeighbors(matchingTiles, checkTile, checkColor) {


    // Check "up"
    if (checkTile > numColumns) {
        // ASSERT:  Not on the top row, check above:
        var up = checkTile - numColumns
        if (matchingTiles.indexOf(up) == -1) {
            // ASSERT:  up tile is not already in the array
            if (boardTiles[up].color == checkColor) {
                // ASSERT:  This is a match.  Add it, and find it's neighbors
                matchingTiles.push(up)
                matchingTiles = findNeighbors(matchingTiles, up, checkColor)
            }
        }
    }

    // Check "right"
    if (checkTile % numColumns != numColumns - 1) {
        // ASSERT:  Not on the fartherst right column, check right
        var right = checkTile + 1
        if (matchingTiles.indexOf(right) == -1) {
            // ASSERT:  right tile not alread in our array
            if (boardTiles[right].color == checkColor) {
                matchingTiles.push(right)
                matchingTiles = findNeighbors(matchingTiles, right, checkColor)
            }
        }
    }

    // Check "down"
    if (checkTile + numColumns < numColumns * numRows) {
        // ASSERT:  Not on the bottom row, check down
        var down = checkTile + numColumns
        if (matchingTiles.indexOf(down) == -1) {
            // ASSERT:  down tile not already in our array
            if (boardTiles[down].color == checkColor) {
                matchingTiles.push(down)
                matchingTiles = findNeighbors(matchingTiles, down, checkColor)
            }
        }
    }

    // Check "left"
    if (checkTile % numColumns > 0) {
        // ASSERT:  Not in the left-most column.  Check left
        var left = checkTile - 1
        if (matchingTiles.indexOf(left) == -1) {
            // ASSERT:  left tile is not already in our array
            if (boardTiles[left].color == checkColor) {
                matchingTiles.push(left)
                matchingTiles = findNeighbors(matchingTiles, left, checkColor)
            }
        }
    }

    return matchingTiles

}


//setInterval(draw, 10);
draw()

//document.addEventListener("keydown", keyDownHandler, false);
//document.addEventListener("keyup", keyUpHandler, false);
document.addEventListener("mousedown", mouseDownHandler, false);

//
//ctx.beginPath();
//ctx.rect(20, 40, 50, 50);
//ctx.fillStyle = "#FF0000";
//ctx.fill();
//ctx.closePath();
//
//ctx.beginPath();
//ctx.arc(240, 160, 20, 0, Math.PI*2, false);
//ctx.fillStyle = "green";
//ctx.fill();
//ctx.closePath();
//
//ctx.beginPath();
//ctx.rect(160, 10, 100, 40);
//ctx.strokeStyle = "rgba(0, 0, 255, 0.5)";
//ctx.stroke();
//ctx.closePath();

//function keyDownHandler(e) {
//    if(e.keyCode == 39) {
//        rightPressed = true;
//    }
//    else if(e.keyCode == 37) {
//        leftPressed = true;
//    }
//}
//
//function keyUpHandler(e) {
//    if(e.keyCode == 39) {
//        rightPressed = false;
//    }
//    else if(e.keyCode == 37) {
//        leftPressed = false;
//    }
//}
//
