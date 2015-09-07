
(deftemplate decision
(slot selectedUnitIndex)
(slot selectedFieldIndex))

 (deftemplate unit
(slot type)
(slot id)
(slot hp)
(slot isAlive)
(slot range)
(slot fieldIndex)
(slot movementSpeed)
(slot canAttack)
(slot isMine))

(deftemplate field
(slot index))

(deftemplate randomNumber
(slot value))