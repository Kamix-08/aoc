import { promises as fs } from 'node:fs'

async function readData() {
    const data = await fs.readFile('./d2.in', 'utf8')

    return data
        .split('\n')
        .map(report => report.split(' ').map(level => Number(level)))
}

export { readData };