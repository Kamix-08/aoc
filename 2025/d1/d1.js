import fs from "node:fs/promises"

async function task1 () {
    const data = await fs.readFile("./d1.in", {encoding: 'utf8'})

    console.log(data
        .split('\n')
        .map(l => [l[0] == 'L', +l.slice(1)])
        .reduce((acc, cur) => {
            acc.cur = (acc.cur + cur[1] * (cur[0] ? 1 : -1)) % 100
            acc.res += (acc.cur == 0)
            return acc
        }, {cur: 50, res: 0})
        .res
    )
}

async function task2 () {
    const data = await fs.readFile("./d1.in", {encoding: 'utf8'})

    console.log(data
        .split('\n')
        .map(l => [l[0] == 'L', +l.slice(1)])
        .reduce((acc, cur) => {
            // screw being optimal
            for (let i = 0; i < cur[1]; i++) {
                acc.cur = (acc.cur + (cur[0] ? 1 : -1)) % 100

                if (acc.cur == 0)
                    acc.res += 1
            }
            return acc
        }, {cur: 50, res: 0})
        .res
    )
}

// task1()
task2()