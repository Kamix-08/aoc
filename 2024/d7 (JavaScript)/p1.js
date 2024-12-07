import { readData } from './d7.js'

function operator(i, res, inp, cur) {
    if (cur == res)                   return true
    if (i >= inp.length || cur > res) return false

    return operator(i+1, res, inp, cur + inp[i])
        || operator(i+1, res, inp, cur * inp[i])
}

(async function main() {
    const data = await readData()

    let total = 0

    for (const set of data) {
        const res    = set[0]
        const inputs = set[1]

        if (operator(1, res, inputs, inputs[0])) {
            total += res
        }
    }

    console.log(total)
})()