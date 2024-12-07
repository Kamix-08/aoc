import { promises as fs } from 'node:fs'

async function readData() {
    const data = await fs.readFile('./d7.in', 'utf8')

    const ret = []

    for (const line of data.split('\n')) {
        const colon = line.indexOf(':')
        ret.push([Number(line.substring(0, colon)), line.substring(colon+2).split(' ').map(e => Number(e))])
    }

    return ret
}

export { readData }