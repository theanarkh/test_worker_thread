const addon = require.resolve('./build/Release/addon.node');
// this makes addon not be unloaded by dlclose
// require(addon);
const { Worker } = require('worker_threads');
new Worker(`require('${addon}').start();`, {eval: true});