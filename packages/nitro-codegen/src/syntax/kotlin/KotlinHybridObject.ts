import { indent } from '../../stringUtils.js'
import { getHybridObjectName } from '../getHybridObjectName.js'
import { createFileMetadataString } from '../helpers.js'
import type { HybridObjectSpec } from '../HybridObjectSpec.js'
import type { SourceFile } from '../SourceFile.js'

// TODO: Make this customizable
const PACKAGE = 'com.margelo.nitro.image'

export function createKotlinHybridObject(spec: HybridObjectSpec): SourceFile[] {
  const name = getHybridObjectName(spec.name)
  const interfaceName = name.TSpec
  const properties = spec.properties.map((p) => p.getCode('kotlin')).join('\n')
  const methods = spec.methods.map((p) => p.getCode('kotlin')).join('\n')

  const interfaceCode = `
${createFileMetadataString(`${interfaceName}.kt`)}

package ${PACKAGE}

/**
 * A Kotlin interface representing the ${spec.name} HybridObject.
 * Implement this interface to create Kotlin-based instances of ${spec.name}.
 */
interface ${interfaceName}: HybridObjectSpec {
  // Properties
  ${indent(properties, '  ')}

  // Methods
  ${indent(methods, '  ')}
}
  `

  const files: SourceFile[] = []
  files.push({
    content: interfaceCode,
    language: 'kotlin',
    name: `${interfaceName}.kt`,
    platform: 'android',
  })
  return files
}