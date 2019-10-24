const N_POINTS = 100
const PADDING = 30
const INF = 1e16
const EPS = 1

let points = new Array(N_POINTS)
let is_point = [];
let beach_line = []
let search_space = []
let points_found = []
let voronoi = []
let SWEEP = 10

function Point() {
  this.x = Math.floor(random(PADDING, width - PADDING))
  this.y = Math.floor(random(PADDING, height - PADDING))
  this.c = color(random(255), random(255), random(255))

  this.show = function() {
    stroke(255)
    strokeWeight(3)
    point(this.x, this.y)
  }

}

function setup() {
  createCanvas(1000, 600)
  for (let j = 0; j < width; j++) {
    col = []
    region = []
    region = []
    for (let i = 0; i < height; i++) {
      col.push(false)
      region.push(-1)
    }
    is_point.push(col)
    voronoi.push(region)
  }
  frameRate(60)
  for (let i = 0; i < N_POINTS; i++) {
    points[i] = new Point()
    is_point[points[i].x][points[i].y] = true
  }
  line_y = 0
  background(0)
}

function draw_points () {
  for (let i = 0; i < points.length; i++) {
    points[i].show()
  }
}

function update_beach_line() {
  beach_line.splice(0, beach_line.length);
  let new_search_space = []
  for (let p = 0; p < search_space.length; p++) {
    let x = search_space[p].x;
    let y = search_space[p].y;
    let dis_to_line = line_y - y
    let min_dis = line_y - y
    let cnt_min_dis = 0
    let id = -1
    for (let i = 0; i < points.length; i++) {
      let dis = Math.sqrt(Math.pow(points[i].x - x, 2) +
        Math.pow(points[i].y - y, 2))
      if (Math.abs(dis - min_dis) < EPS) {
        cnt_min_dis += 1
      } else if (dis < min_dis) {
        min_dis = dis
        cnt_min_dis = 1
        id = i
      }
    }
    if (min_dis < dis_to_line && cnt_min_dis >= 1) {
      voronoi[x][y] = id 
      stroke(points[id].c)
      strokeWeight(1)
      point(x, y)
    } else {
      new_search_space.push(createVector(x, y))
    }
  }
  search_space = new_search_space
}

function sweep_line() {
  for (let y = line_y; y < line_y + SWEEP; y++) {
    for (let x = 0; x < width; x++) {
      if (is_point[x][y]) continue
      search_space.push(createVector(x, y))
    }
  }
  stroke(0)
  strokeWeight(1)
  line(0, line_y, width, line_y)
  line_y += SWEEP
  stroke(255, 0, 0)
  strokeWeight(1)
  line(0, line_y, width, line_y)
}

function draw() {
  draw_points()
  update_beach_line()
  sweep_line()
  if (line_y > 3 * height) noLoop()
}
