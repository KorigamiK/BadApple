import "./style.css";

const sleep = (ms: number) => new Promise((r) => setTimeout(r, ms));

var favicon = document.getElementById("favicon");

const canvas = document.getElementById("bad-apple")! as HTMLCanvasElement;
const ctx = canvas.getContext("2d");
canvas.className = "fav-canvas";

const height = 16;
const width = 16;

canvas.width = height;
canvas.height = width;

const load_frames = (data: string) => {
  const matrices: number[][][][] = [];
  const lines = data.split("\n");

  for (
    let mat_number = 0;
    mat_number < Math.floor(lines.length / height);
    mat_number++
  ) {
    matrices.push([]);
    const matrix = matrices[mat_number];

    for (let y = 0; y < height; y++) {
      const row_data = lines[mat_number * height + y].split(",");
      const row = [];
      //row_data.length / 3
      for (let x = 0; x < width; x++) {
        const element = [];
        for (let e = 0; e < 3; e++) {
          element.push(parseInt(row_data[x * 3 + e]));
        }
        row.push(element);
      }
      matrix.push(row);
    }
    // break;
  }
  return matrices;
};

const set_favicon = () => {
  //var newIcon = favicon.cloneNode(true);
  //newIcon.setAttribute("href", canvas.toDataURL());
  //favicon.parentNode.replaceChild(newIcon, favicon);
  favicon?.setAttribute("href", canvas.toDataURL());
  // history.replaceState(null, null, window.location.hash == "#1" ? "#0" : "#1");
};

const main = async () => {
  const frames_csv = await (await fetch("/frames.csv")).text();
  const frames = load_frames(frames_csv);

  const imgData = ctx!.getImageData(0, 0, 16, 16);
  const data = imgData.data; // the array of RGBA values

  for (let number = 0; number < frames.length; number++) {
    const frame = frames[number];
    // https://stackoverflow.com/questions/13826319/copy-a-2-dimensional-pixel-array-to-a-javascript-canvas
    for (var i = 0; i < height; i++) {
      for (var j = 0; j < width; j++) {
        var s = 4 * i * width + 4 * j; // calculate the index in the array
        var x = frame[i][j]; // the RGB values
        data[s] = x[0];
        data[s + 1] = x[1];
        data[s + 2] = x[2];
        data[s + 3] = 255; // fully opaque
      }
    }
    ctx?.putImageData(imgData, 0, 0);
    set_favicon();
    await sleep(200);
  }
};

main();
