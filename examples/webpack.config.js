const path = require('path')
const {BundleAnalyzerPlugin} = require('webpack-bundle-analyzer')
const {ANALYZE_BUNDLE} = process.env


module.exports = {
  entry: {
    lineChart: '../lib/es6/examples/lineChart.js',
  },

  output: {
    path: path.join(__dirname, 'dist'),
    filename: '[name].js',
  },

  plugins: ANALYZE_BUNDLE ? [new BundleAnalyzerPlugin()] : [],

  devtool: 'cheap-eval-source-map'
}

