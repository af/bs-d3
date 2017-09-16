const fs = require('fs')
const path = require('path')
const {BundleAnalyzerPlugin} = require('webpack-bundle-analyzer')
const {ANALYZE_BUNDLE} = process.env


// Generate a separate entry script for each example source file:
const sourceDir = path.join(__dirname, '..', 'lib', 'es6', 'examples')
const exampleSources = fs.readdirSync(sourceDir)
const entry = exampleSources.reduce((acc, src) => {
    const entryName = src.split('.')[0]
    const fullPath = path.join(sourceDir, src)
    return {...acc, [entryName]: fullPath}
}, {})

module.exports = {
    entry,

    output: {
        path: path.join(__dirname, 'dist'),
        filename: '[name].js',
    },

    plugins: ANALYZE_BUNDLE ? [new BundleAnalyzerPlugin()] : [],

    devtool: 'cheap-eval-source-map'
}
