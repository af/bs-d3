const path = require('path')

module.exports = {
  entry: {
    lineChart: '../lib/es6/examples/lineChart.js',
  },
  output: {
    path: path.join(__dirname, 'dist'),
    filename: '[name].js',
  },
}

