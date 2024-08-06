import deepEqual from 'deep-equal'

export type Must = 'equals' | 'throws'

const _someType = typeof false
export type JSType = typeof _someType

export class State<T> {
  readonly errorThrown: unknown | undefined
  readonly result: T | undefined

  constructor(result: T | undefined, error: unknown | undefined) {
    this.result = result
    this.errorThrown = error
  }

  private onPassed(): void {}

  private onFailed(reason: string): void {
    throw new Error(reason)
  }

  didThrow(): State<T> {
    if (this.errorThrown == null) {
      this.onFailed(
        `Expected test to throw an error, but no error was thrown! Instead it returned a result: ${this.result}`
      )
    } else {
      this.onPassed()
    }
    return this
  }

  didNotThrow(): State<T> {
    if (this.errorThrown != null) {
      this.onFailed(
        `Expected test to not throw any errors, but an error was thrown! Error: ${this.errorThrown}`
      )
    } else {
      this.onPassed()
    }
    return this
  }

  equals(other: T): State<T> {
    if (!deepEqual(this.result, other)) {
      this.onFailed(
        `Expected "${this.result}" (${typeof this.result}) to equal "${other}" (${typeof other}), but they are not equal!`
      )
    } else {
      this.onPassed()
    }
    return this
  }

  didReturn(type: JSType): State<T> {
    if (typeof this.result !== type) {
      this.onFailed(
        `Expected ${this.result}'s type (${typeof this.result}) to be ${type}!`
      )
    } else {
      this.onPassed()
    }
    return this
  }

  toContain(key: keyof T): State<T> {
    if (!Object.keys(this.result as any).includes(key as any)) {
      this.onFailed(
        `Expected "${this.result}" to contain ${String(key)}, but it didn't! Keys: ${Object.keys(this.result as any)}`
      )
    } else {
      this.onPassed()
    }
    return this
  }

  toBeArray(): State<T> {
    if (!Array.isArray(this.result)) {
      this.onFailed(
        `Expected "${this.result}" (${typeof this.result}) to be an array, but it isn't!`
      )
    } else {
      this.onPassed()
    }
    return this
  }
}

export function it<T>(action: () => Promise<T>): Promise<State<T>>
export function it<T>(action: () => T): State<T>
export function it<T>(
  action: () => T | Promise<T>
): State<T> | Promise<State<T>> {
  try {
    const syncResult = action()
    if (syncResult instanceof Promise) {
      return syncResult
        .then((asyncResult) => new State<T>(asyncResult, undefined))
        .catch((error) => new State<T>(undefined, error))
    }
    return new State<T>(syncResult, undefined)
  } catch (e) {
    return new State<T>(undefined, e)
  }
}

export function callback<T, R>(func: (...args: T[]) => R): (...args: T[]) => R {
  return func
}