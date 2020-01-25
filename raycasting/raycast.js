const TILE_SIZE = 32;  // the size of the square.
const MAP_NUM_ROWS = 11; // Number of rows in map.
const MAP_NUM_COLS = 15; // Number of columns in the map.

// the follwing consts have something to do with the rosolution
const WINDOW_WIDTH = MAP_NUM_COLS * TILE_SIZE; // The size of the window_width
const WINDOW_HEIGHT = MAP_NUM_ROWS * TILE_SIZE;	// the size of the window_height.

class Map {
	constructor() {
		this.grid = [
			[1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
			[1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1],
			[1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1],
			[1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1],
			[1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1],
			[1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1],
			[1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
			[1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
			[1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1],
			[1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
			[1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
		];
	}
	hasWallAt(x, y) {
		if (x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOW_HEIGHT)
			return true;
		var mapGridIndexX = Math.floor(x / TILE_SIZE);
		var mapGridIndexY = Math.floor(y / TILE_SIZE);
		return this.grid[mapGridIndexY][mapGridIndexX] != 0;
	}
	render() {
		for (var i = 0; i < MAP_NUM_ROWS; i++) {
			for (var j = 0; j < MAP_NUM_COLS; j++) {
				var tileX = j * TILE_SIZE; // x coordinate for the tile.
				var tileY = i * TILE_SIZE; // y coordinate for the tile.
				var tileColor = this.grid[i][j] == 1 ? "#222" : "#fff"; // tile/square color.
				stroke("#222");
				fill(tileColor);
				rect(tileX, tileY, TILE_SIZE, TILE_SIZE); // this func'll draw a rectangle.
			}
		}
	}
}

class Player {
	constructor() {
		this.x = WINDOW_WIDTH / 2;
		this.y = WINDOW_HEIGHT / 2
			this.radius = 3;
		this.turnDirection = 0; // -1 if left, +1 if right
		this.walkDirection = 0; // -1 if back, +1 if front
		this.rotationAngle = Math.PI / 2;
		this.moveSpeed = 2.0;
		this.rotationSpeed = 2 * (Math.PI/180);
	}
	update(){
		console.log(this.turnDirection);
		this.rotationAngle += this.turnDirection * this.rotationSpeed;

		var moveStep = this.walkDirection * this.moveSpeed;
		var newPlayerX = this.x + Math.cos(this.rotationAngle) * moveStep;
		var newPlayerY = this.y + Math.sin(this.rotationAngle) * moveStep;
		if (!grid.hasWallAt(newPlayerX, newPlayerY))
		{
			this.x = newPlayerX;
			this.y = newPlayerY;
		}
	}
	renderPlayer() {
		noStroke();
		fill("red");
		circle(this.x, this.y, this.radius);
		stroke("red");
		line(
				this.x,
				this.y,
				this.x + Math.cos(this.rotationAngle) * 30,
				this.y + Math.sin(this.rotationAngle) * 30
			);
	}
}

// Global vars
var player = new Player();
var grid = new Map();

function keyPressed() {
	if (keyCode == UP_ARROW) {
		player.walkDirection = +1;
	}
	else if (keyCode == DOWN_ARROW) {
		player.walkDirection = -1;
	}
	else if (keyCode == RIGHT_ARROW) {
		player.turnDirection = +1;
	}
	else if (keyCode == LEFT_ARROW) {
		player.turnDirection = -1;
	}
}

function keyReleased() {
	if (keyCode == UP_ARROW) {
		player.walkDirection = 0;
	}
	else if (keyCode == DOWN_ARROW) {
		player.walkDirection = 0;
	}
	else if (keyCode == RIGHT_ARROW) {
		player.turnDirection = 0;
	}
	else if (keyCode == LEFT_ARROW) {
		player.turnDirection = 0;	
	}
}
function setup() {
	createCanvas(WINDOW_WIDTH, WINDOW_HEIGHT);
}

function update() {
	player.update();
}

function draw() {
	update();

	grid.render(); // Make the grid object draw the map.
	player.renderPlayer();
}
